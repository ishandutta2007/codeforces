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
int a[2000][2000];
int main(){
    int n,m,k,x,y,z;
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin>>n>>m>>k;
if ((n%2)!=(m%2)){
cout<<0<<endl;
return 0;
}
    bool fl=false;
    if (n>m){
        swap(n,m);
        fl=true;
    }
    for (int i=0;i<k;i++){
        cin>>x>>y>>z;
        x--;
        y--;
        if (fl) a[y][x]=z;
        else    a[x][y]=z;
    }
    int p;
    cin>>p;
    bool bl=true;
    int ans=0;
    for (int i=0;i<m;i++){
        int sum=0;
        int cnt=0;
        for (int j=0;j<n;j++){
            if (a[j][i]==0) cnt++;
            if (a[j][i]==-1) sum=(sum+1)%2;
        }
        if (cnt==n && bl){
            bl=false;
            continue;
        }
        if (cnt==0 && sum==0){
            cout<<0<<endl;
            return 0;
        }
        for (int j=1;j<=cnt-1;j++){
            ans++;
        }
    }
    int ff=1;
    for (int i=0;i<ans;i++){
        ff=(ff*2)%p;
    }
    cout<<ff<<endl;
    return 0;
}