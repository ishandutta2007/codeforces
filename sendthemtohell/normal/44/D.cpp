#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back

ld l(int x1,int y1,int  z1,int x2,int y2,int z2){
        return sqrt((ld)(x2-x1)*(x2-x1)+(ld)(y2-y1)*(y2-y1)+(ld)(z2-z1)*(z2-z1));
}


int main()
{
    double tt;
    ios_base::sync_with_stdio(false);
    cout<<setprecision(20);
    cout<<fixed;
    int n;
    cin>>n;
    int x,y,z;
    cin>>x>>y>>z;
    vector<int> X,Y,Z;
    for(int i=0;i<n-1;++i){
            int xc,yc,zc;
            cin>>xc>>yc>>zc;
            X.pb(xc);
            Y.pb(yc);
            Z.pb(zc);
    }
    tt=clock();
    ld mmin=100*100*100;
    for(int i=0;i<X.size();++i){
            for(int j=i+1;j<X.size();++j){
                    //cout<<mmin<<endl;
                    //cout<<"rrr  "<<l(x,y,z,X[i],Y[i],Z[i])<<endl;
                    mmin=min(mmin,(l(x,y,z,X[i],Y[i],Z[i])+l(x,y,z,X[j],Y[j],Z[j])+l(X[j],Y[j],Z[j],X[i],Y[i],Z[i]))/2.);
            }
    }
    cout<<mmin<<endl;
    #ifdef LOCAL
        cout<<((ld)clock()-tt)/CLOCKS_PER_SEC<<endl;
    #endif // LOCAL
    return 0;
}