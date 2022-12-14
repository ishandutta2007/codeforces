//In the name of God
#include <iostream>
using namespace std;
const long long oo = (long long)1 << 59;
long long check(string S){
    if(S.length() > 7)
        return -oo;
    if(S == "0")
        return 0;
    if(S[0] == '0')
        return -oo;
    long long ret = 0;
    for(int i = 0; i < S.size();i++){
        ret *= 10;
        ret += S[i]-'0';
    }
    if(ret > 1e6)
        return -oo;
    return ret;
}
int main(){
    string S;
    cin >> S;
    int n = S.size();
    long long ans = -1;
    for(int i = 0; i < n;i++){
        for(int j = i+2; j < n;j++){
            long long cnt = 0;
            string P ="";
            for(int k = 0; k <= i;k++){
                P+=S[k];
            }
            cnt += check(P);
            P = "";
            for(int k = i+1; k < j;k++){
                P+=S[k];
            }
            cnt += check(P);
            P = "";
            for(int k = j; k < n;k++){
                P += S[k];
            }
            cnt += check(P);
            P = "";
            ans = max(ans,cnt);
        }
    }
    cout << ans << endl;
    return 0;
}