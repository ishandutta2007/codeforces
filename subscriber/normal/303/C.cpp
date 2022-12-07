#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<memory.h>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<sstream>
#define mp make_pair
#define pb push_back
#define F first
#define S second
#define SS stringstream
#define sqr(x) ((x)*(x))
#define m0(x) memset(x,0,sizeof(x))
#define m1(x) memset(x,63,sizeof(x))
#define CC(x) cout << (x) << endl
#define pw(x) (1ull<<(x))
#define M 1000000007
using namespace std;
typedef pair<int,int> pt;

int n,k,a[5555],ko[1000111];
vector<int>q[1000111];

int main(){
//    freopen("1.in","r",stdin);  
//    freopen("1.out","w",stdout);    
    cin >> n >> k;
    for (int i=0;i<n;i++)cin >> a[i];
    sort(a,a+n);
    for (int i=0;i<n;i++)for (int j=0;j<i;j++)ko[a[i]-a[j]]++;
    for (int i=0;i<n;i++)for (int j=0;j<i;j++)if (ko[a[i]-a[j]]<=10){
        q[a[i]-a[j]].pb(i);
        q[a[i]-a[j]].pb(j);
    }
    for (int ans=1;ans<=1000001;ans++){
        vector<int>vr,cl;
        int p=0;
        for (int i=ans;i<=1000000;i+=ans){
            p+=ko[i];
            if (p>10)break;
        }
        if(p>10)continue;        
        for (int i=ans;i<=1000000;i+=ans)for (int j=0;j<q[i].size();j++)vr.pb(q[i][j]),cl.pb(a[q[i][j]]%ans);
        sort(vr.begin(),vr.end());
        sort(cl.begin(),cl.end());
        int e=0;
        for (int i=1;i<vr.size();i++)if (vr[i]!=vr[i-1])e++;
        for (int i=1;i<cl.size();i++)if (cl[i]!=cl[i-1])e--;
        if (e<=k){
            cout << ans << endl;
            break;
        }
    }
    return 0;
}