#include <iostream>
#define MOD 1000000007
using namespace std;

string s, tmp;
int N;
char st[100005];
string tr[100005];
long long val[100005][10];
int len[100005][10];
bool seen[100005][10];

pair<long long, int> eval_str(string const &arg, int i);

void calc_char(char c, int i){
    if(seen[i][c-'0']) return;
    seen[i][c-'0'] = true;

    if(i == N){
        val[i][c-'0'] = c-'0';
        len[i][c-'0'] = 1;
        return;
    }

    if(st[i] != c){
        calc_char(c, i+1);
        val[i][c-'0'] = val[i+1][c-'0'];
        len[i][c-'0'] = len[i+1][c-'0'];
        return;
    }

    pair<long long, int> res = eval_str(tr[i], i+1);
    len[i][c-'0'] = res.second;
    val[i][c-'0'] = res.first;
}

long long mod_pow(long long base, long long exp){
    if(exp == 0) return 1LL;
    if(exp % 2) return (base * mod_pow((base * base) % MOD, exp/2)) % MOD;
    return mod_pow((base * base) % MOD, exp/2);
}

long long eval(long long value, long long zeroes){
    return (value * mod_pow(10, zeroes)) % MOD;
}

pair<long long, int> eval_str(string const &arg, int i){
    long long ret = 0;
    int lsf = 0;

    for(int j=arg.length()-1; j>=0; j--){
        calc_char(arg[j], i);
        ret = (ret + eval(val[i][arg[j]-'0'], lsf)) % MOD;
        lsf = (len[i][arg[j]-'0'] + lsf) % (MOD-1);
    }

    return make_pair(ret, lsf);
}

int main(){
    std::ios_base::sync_with_stdio(false);

    cin >> s >> N;
    for(int i=0; i<N; i++){
        cin >> tmp;
        st[i] = tmp.substr(0, 1)[0];
        tr[i] = tmp.substr(3);
    } 

    cout << eval_str(s, 0).first << endl;
    return 0;
}