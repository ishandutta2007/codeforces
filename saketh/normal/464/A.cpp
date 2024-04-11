#include <iostream>
using namespace std;

int N, P;
string inp;
int block[256];

char next_free(char val){
    int sval = val - 'a';

    for(int up = 1; (sval+up)<P; up++)
        if(sval + up < P && !block[val + up]){
            return val + up;
        }

    return 0;
}

char lowest_free(){
    for(int sval = 0; sval < P; sval++)
        if(!block['a' + sval])
            return 'a' + sval;
    return 0;
}

string try_incr(string copy, int idx){
    copy[idx] = next_free(copy[idx]);
    if(copy[idx] == 0) return "FAIL";
    for(int j = idx+1; j<N; j++){
        if(j-3 >= 0) block[copy[j-3]]--;
        if(j-1 >= 0) block[copy[j-1]]++;
                                                
        copy[j] = lowest_free();       
        if(copy[j] == 0) return "FAIL";
    }

    return copy;
}

int main(){
    cin >> N >> P >> inp;

    if(N > 1) block[inp[N-2]] ++;
    if(N > 2) block[inp[N-3]] ++;

    int idx = -1;
    for(int i=(N-1); i>=0; i--){
        for(char v = 'a'; v<='z'; v++)
            block[v] = 0;

        if(i >= 2) block[inp[i-2]]++;
        if(i >= 1) block[inp[i-1]]++;

        string res = try_incr(inp, i);
        if(res != "FAIL"){
            cout << res << endl;
            return 0;
        }
    }

    cout << "NO" << endl;
    return 0;
}