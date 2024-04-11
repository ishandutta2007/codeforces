#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define y1 kdjf

const int N = 3e5 + 11;

int x1[N],y1[N],x2[N],y2[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;
    multiset<int> xx1,yy1,xx2,yy2;
    for (int i=1; i<=n; i++)
    {
        cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
        xx1.insert(x1[i]);
        yy1.insert(y1[i]);
        xx2.insert(x2[i]);
        yy2.insert(y2[i]);
    }
    for (int i=1; i<=n; i++)
    {
        xx1.erase(xx1.find(x1[i]));
        yy1.erase(yy1.find(y1[i]));
        xx2.erase(xx2.find(x2[i]));
        yy2.erase(yy2.find(y2[i]));

        int l1=*(xx1.rbegin());
        int l2=*(xx2.begin());
        int r1=*(yy1.rbegin());
        int r2=*(yy2.begin());

        xx1.insert(x1[i]);
        yy1.insert(y1[i]);
        xx2.insert(x2[i]);
        yy2.insert(y2[i]);

        if (l1<=l2&&r1<=r2) {cout<<l1<<" "<<r1; return 0;}
    }
}