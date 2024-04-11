#include<cmath>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
#include<ctime>
using namespace std;
#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define y1 gfdsgfdsg
typedef long long ll;
int main(){
    int n,x,m,y;
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    cin>>n>>x>>m>>y;
    int ds=abs(x-y);
    ll ans=n+m+1;
    for (int i=1;i<=n;i++){
        if (ds<=i-1){
            if (m>i-1-ds){
                ans++;
                if (m<=i-1+ds) ans+=(m-(i-ds))*2; else {
                    ans+=(i-1+ds-(i-ds))*2;
                    //if (m>i-1+ds) ans++;
                    //if (m>i+ds) ans++;

                }
            }
        }
        if (ds>=i){
            if (m>ds-i){
                ans++;
                if (m<=i-1+ds) ans+=(m-(ds-i+1))*2; else {
                    ans+=(i-1+ds-(ds-i+1))*2;
                    //if (m>i-1+ds) ans++;
                }
            }
        }
    }
    for (int i=1;i<=m;i++){
        if (y+i<=x+n && y-i>=x-n) ans--;
    }
    cout<<ans<<endl;
	return 0;
}