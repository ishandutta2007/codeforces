#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <cmath>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);(i)<(b);(i)++)
#define MP make_pair
#define ALL(a) ((a).begin(),(a).end())
#define PB push_back
#define PII pair<int,int>

typedef long long ll;
typedef unsigned long long ull;
    int x[8],y[8];
double dist(int i,int j){
       return ((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
       }
vector<int> a; 
int main()
{

    FOR(i,0,8)
    cin>>x[i]>>y[i];
    FOR(i1,0,8)
    FOR(i2,0,8)
    FOR(i3,0,8)
    FOR(i4,0,8)
    if (i1!=i2 && i1!=i3 && i1!=i4 && i2!=i3 && i2!=i4 && i3!=i4)
    {
        //cout<<i1<<' '<<i2<<' '<<i3<<' '<<i4<<endl;
        if(dist(i1,i2)!=dist(i2,i3) || dist(i3,i2)!=dist(i3,i4) || dist(i3,i4)!=dist(i4,i1) || dist(i1,i4)!=dist(i2,i1))
            continue;
        //cout<<i1<<' '<<i2<<' '<<i3<<' '<<i4<<endl;
        if (((x[i2]-x[i1])*(x[i4]-x[i1])+(y[i2]-y[i1])*(y[i4]-y[i1]))!=0) continue;
        //cout<<i1<<' '<<i2<<' '<<i3<<' '<<i4<<endl;
        if (((x[i2]-x[i1])*(y[i4]-y[i1])-(y[i2]-y[i1])*(x[i4]-x[i1]))==0) continue;
        a.clear();
        FOR(i,0,8)
        if (i!=i1 && i!=i2 && i!=i3 && i!=i4)
        a.PB(i);
        sort(a.begin(),a.end());
        do{
            if(dist(a[0],a[1])!=dist(a[2],a[3]) || dist(a[1],a[2])!=dist(a[0],a[3])) continue;
            if ((x[a[1]]-x[a[0]])*(x[a[3]]-x[a[0]])+(y[a[1]]-y[a[0]])*(y[a[3]]-y[a[0]])!=0) continue;
            if ((x[a[1]]-x[a[0]])*(y[a[3]]-y[a[0]])-(y[a[1]]-y[a[0]])*(x[a[3]]-x[a[0]])==0) continue;
            cout<<"YES"<<endl<<i1+1<<' '<<i2+1<<' '<<i3+1<<' '<<i4+1<<endl<<a[0]+1<<' '<<a[1]+1<<' '<<a[2]+1<<' '<<a[3]+1<<endl;
           //system("pause");
           return 0;
           }
           while (next_permutation(a.begin(),a.end()));
    }
    cout<<"NO";    
    //system("pause");
    return 0;
}