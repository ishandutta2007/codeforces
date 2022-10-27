#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

typedef long long LL;
const int N = 2000 + 10;
int n,k;

char s[N][N];
int a[N][N];

void getrow(int x){
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(s[x][i]=='B') v.push_back(i);
    }
    int x1=1,y1=1,x2=n,y2=n;
    if(v.size()) {
        x1=max(1,x-k+1);
        y1=max(1,v[(int)v.size()-1]-k+1);
        x2=x;
        y2=v[0];
    }
    if(x1<=x2 && y1<=y2) {
        a[x1][y1]++;
        a[x2+1][y2+1]++;
        a[x1][y2+1]--;
        a[x2+1][y1]--;
    }
}

void getcol(int x) {
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(s[i][x]=='B') v.push_back(i);
    }
    int x1=1,y1=1,x2=n,y2=n;
    if(v.size()) {
        y1=max(1,x-k+1);
        x1=max(1,v[(int)v.size()-1]-k+1);
        y2=x;
        x2=v[0];
    }
    if(x1<=x2 && y1<=y2) {
        a[x1][y1]++;
        a[x2+1][y2+1]++;
        a[x1][y2+1]--;
        a[x2+1][y1]--;
    }    
}

int main() {
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<=n;i++) {
        getrow(i); getcol(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            ans=max(ans, a[i][j]);
        }
    }
    cout<<ans<<endl;
}