#include <iostream>
using namespace std;

string key;
int A, B;
long long ra[1000005], rb[1000005];

long long mod_pow(long long b, long long e, long long m){
    if(e == 0) return 1LL;
    long long ret = mod_pow((b*b)%m, e/2, m);
    return (ret * ((e%2)?b:1LL))%m;
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin >> key >> A >> B;

    for(int i=1; i<=key.size(); i++)
        ra[i] = (10 * ra[i-1] + key[i-1] - '0') % A;

    for(int i=key.size() - 1; i>=0; i--)
        rb[i] = (rb[i+1] + (key[i] - '0') * mod_pow(10, key.size()-1-i, B)) % B;

    for(int i=1; i<key.size(); i++){
        if(key[i] == '0') continue;
        if(ra[i]!=0 || rb[i]!=0) continue;
        cout << "YES\n";
        cout << key.substr(0, i) << "\n";
        cout << key.substr(i) << endl;
        return 0;
    }

    cout << "NO" << endl;
    return 0;
}