//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
typedef long long ll;
const long long Mod = 1e9 + 7;
const ll x = 37;
const int Maxf = 1e6 + 9;
ll f[Maxf];
char S[Maxf];
ll pw(ll a,ll b){
    return b?(pw((a * a)%Mod,b >> 1) * (b & 1?a:1))%Mod:1;
}
ll hash[Maxf];
int z[Maxf];
int is_good[Maxf];
int sum[Maxf];
bool ans[Maxf];
int main(){
    int n,k;
    cin >> n >> k;
    scanf("%s",&S);
    int L = 0,R = 0;
    z[0] = n;
    for(int i = 1; i < n;i++){
        if(i > R){
            L = i;
            R = i;
            while(R < n){
                if(S[R] == S[R - i])
                    R++;
                else
                    break;
            }
            z[i] = R - L;
            R--;
        }else{
            int id = i - L;
            if(z[id] < R - i + 1)
                z[i] = z[id];
            else{
                L = i;
                while(R < n){
                    if(S[R] == S[R - i])
                        R++;
                    else
                        break;
                }
                z[i] = R - L;
                R--;
            }
        }
    }
    for(int i = 0; i < n;i++){
        if((i + 1) % k == 0){
            int s = (i + 1) / k;
            if(i < s + z[s]){
                is_good[i] = 1;
                ans[i] = 1;
                if(i != n-1 && z[i+1] > 0){
                    sum[i+1] += 1;
                    sum[i + min(s,z[i+1]) + 1] -= 1;
                }
            }
        }
    }
    int cnt = 0;
    for(int i = 0; i < n;i++){
        cnt += sum[i];
        if(cnt > 0)
            ans[i] = 1;
    }
    for(int i = 0; i < n;i++)
        printf("%d",ans[i]);
    cout << endl;
    return 0;
    
}