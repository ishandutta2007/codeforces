#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

double dis(double x1,double y1,double x2,double y2)
{
    return (sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)));
}

int main()
{
    double y1,y2,yw,xb,yb,r,ye,yq,k1,b1,nx,ar2;
    cin>>y1>>y2>>yw>>xb>>yb>>r;
    ye=y1+r;
    yq=yw-r;
    ye=yq+(yq-ye);
    k1=(yb-ye)/xb;
    b1=ye;
    nx=(yq-b1)/k1;
    ar2=(y2-(y1+r))*nx;
    //cout<<ye<<" "<<y2<<" "<<nx<<" "<<ar2<<endl;
    if (dis(0,ye,nx,yq)*r>ar2) cout<<-1<<endl; else printf("%.10lf\n",nx);

    return 0;
}