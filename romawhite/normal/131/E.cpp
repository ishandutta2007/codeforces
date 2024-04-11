    #include <cstdlib>
    #include <iostream>
    #include <vector>
    #include <set>
    #include <cstdio>
    #include <cmath>
    #include <string>
    #include <algorithm>
    #include <map>
    #include <memory.h>

    using namespace std;

    #define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
    #define MP make_pair
    #define ALL(a) ((a).begin(),(a).end())
    #define PB push_back
    #define PII pair<int,int>

    typedef long long ll;
    typedef unsigned long long ull;
    const int INF=2000000000;
    
    int main(){
        int n,m,k,l;
    cin>>n>>m;
    vector<int> r[n+1];
    vector<int> c[n+1];
    vector<int> d[2*n+2];
    vector<int> d1[2*n+2];
    int minr[n+1],minc[n+1],mind[2*n+2],maxr[n+1],maxc[n+1],maxd[2*n+2],mind1[2*n+2],maxd1[2*n+2];
    int minrv[n+1],mincv[n+1],mindv[2*n+2],maxrv[n+1],maxcv[n+1],maxdv[2*n+2],mind1v[2*n+2],maxd1v[2*n+2];
    FOR(i,0,n+1)
    {
              minr[i]=INF;minc[i]=INF;maxr[i]=-1;maxc[i]=-1;
    }
FOR(i,0,2*n+2)
    {
              mind[i]=INF;mind1[i]=INF;maxd[i]=-1;maxd1[i]=-1;
    }
    FOR(i,0,m)
    {        
             cin>>k>>l;
             r[k].PB(i);
             c[l].PB(i);
             d[k+l].PB(i);
             d1[k-l+n].PB(i);
            if (maxr[k]<l) {maxr[k]=l;maxrv[k]=i;}
            if (maxc[l]<k) {maxc[l]=k;maxcv[l]=i;}
            if (minr[k]>l) {minr[k]=l;minrv[k]=i;}
            if (minc[l]>k) {minc[l]=k;mincv[l]=i;}
            if (maxd[k+l]<l) {maxd[k+l]=l;maxdv[k+l]=i;}
            if (maxd1[k-l+n]<l) {maxd1[k-l+n]=l;maxd1v[k-l+n]=i;}
            if (mind[k+l]>l) {mind[k+l]=l;mindv[k+l]=i;}
            if (mind1[k-l+n]>l) {mind1[k-l+n]=l;mind1v[k-l+n]=i;}
            }
    vector<int> res(m+1,0);
    FOR(i,1,n+1)
    if (r[i].size()>1){
    res[maxrv[i]]--;
    res[minrv[i]]--;
    FOR(j,0,r[i].size())
    res[r[i][j]]+=2;
}
   FOR(i,1,n+1)
    if (c[i].size()>1){
    res[maxcv[i]]--;
    res[mincv[i]]--;
    FOR(j,0,c[i].size())
    res[c[i][j]]+=2;
}
            FOR(i,1,2*n+2)
    if (d[i].size()>1){
    res[maxdv[i]]--;
    res[mindv[i]]--;
    FOR(j,0,d[i].size())
    res[d[i][j]]+=2;
}  
         FOR(i,1,2*n+2)
    if (d1[i].size()>1){
    res[maxd1v[i]]--;
    res[mind1v[i]]--;
    FOR(j,0,d1[i].size())
    res[d1[i][j]]+=2;
}  
   int ans[10];
   memset(ans,0,sizeof(ans));
   FOR(i,0,m)
    ans[res[i]]++;
    FOR(i,0,9)
    cout<<ans[i]<<' ';
    return 0;
}