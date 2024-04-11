#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int N = 1e6 + 11;

int a[10];

int get(int l, int r)
{
    cout<<"? "<<l<<" "<<r<<endl;
    int x;
    cin>>x;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    a[1]=4;
    a[2]=8;
    a[3]=15;
    a[4]=16;
    a[5]=23;
    a[6]=42;
    int t1=get(1,2);
    int t2=get(2,3);
    int t3=get(3,4);
    int t4=get(4,5);
    for (int x1=1; x1<=6; x1++)
    for (int x2=1; x2<=6; x2++)
    if (x2!=x1&&a[x1]*a[x2]==t1)
    for (int x3=1; x3<=6; x3++)
    if (x3!=x1&&x3!=x2&&a[x2]*a[x3]==t2)
    for (int x4=1; x4<=6; x4++)
    if (x4!=x1&&x4!=x2&&x4!=x3&&a[x3]*a[x4]==t3)
    for (int x5=1; x5<=6; x5++)
    if (x5!=x1&&x5!=x2&&x5!=x3&&x5!=x4&&a[x4]*a[x5]==t4)
    for (int x6=1; x6<=6; x6++)
    if (x6!=x1&&x6!=x2&&x6!=x3&&x6!=x4&&x5!=x6)
    {
        cout<<"! "<<a[x1]<<" "<<a[x2]<<" "<<a[x3]<<" "<<a[x4]<<" "<<a[x5]<<" "<<a[x6]<<endl;
        return 0;
    }



}