//In the name of God
#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int (i)=(a);(i) < (b); ++(i))
#define Rof(i,a,b) for(int (i)=(a);(i) >= (b); --(i))
#define mkp make_pair
#define XX first
#define YY second
#define pb push_back
const int Maxn = 1e6 + 9;
const int Mod = 1e9 + 7;
int arr[Maxn],z[Maxn];
char S[Maxn];
int mark[Maxn];
typedef long long ll;
ll pw(ll a,ll b){
    return b?(pw((a * a) % Mod, b >> 1) * (b & 1?a:1))%Mod:1;
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    scanf("%s",S);
    int len = strlen(S);
    For(i,0,m){
        scanf("%d",&arr[i]);
        --arr[i];
    }
    int L = 0,R = 0;
    z[0] = n;
    For(i,1,n){
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
    int r = -1;
    For(i,1,m){
        if(arr[i] + z[arr[i] - arr[i-1]] <= arr[i-1] + len - 1){
            printf("0\n");
            return 0;
        }
    }
    For(i,0,m){
        For(j,max(r,arr[i]),arr[i] + len)
            mark[j] = 1;
        r = arr[i] + len;
    }
    int x = 0;
    For(i,0,n)
        x += mark[i] ^ 1;
    printf("%d\n",pw(26,x));
    return 0;
}