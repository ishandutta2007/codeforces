#include<bits/stdc++.h>
using namespace std;
struct piece
{
    char typ;
    int x;
    int y;
};

vector<piece> v,h,d1,d2;
piece a[1000000];
bool c1(piece a,piece b)
{
    return a.x<b.x;
}
bool c2(piece a,piece b)
{
    return a.y<b.y;
}
int main()
{
    int n;
    cin>>n;
    int X,Y;
    cin>>X>>Y;
    for (int i=0;i<n;i++)
        cin>>a[i].typ>>a[i].x>>a[i].y;
    for (int i=0;i<n;i++)
    {
        if (X-Y==a[i].x-a[i].y)
            d1.push_back(a[i]);
        else if (X+Y==a[i].x+a[i].y)
            d2.push_back(a[i]);
        else if (X==a[i].x)
            h.push_back(a[i]);
        else if (Y==a[i].y)
            v.push_back(a[i]);
    }
    piece mx;
    mx.x=1000000001;
    mx.y=1000000001;
    mx.typ='X';
    d1.push_back(mx);
    d2.push_back(mx);
    h.push_back(mx);
    v.push_back(mx);
    sort(d1.begin(),d1.end(),c1);
    sort(d2.begin(),d2.end(),c1);
    sort(h.begin(),h.end(),c2);
    sort(v.begin(),v.end(),c1);
    bool is=0;
    for (int i=0;i<h.size();i++)
    {
        if (h[i].y>Y)
        {
            int l=i-1;
            if (l>=0)
            {
                if (h[l].typ=='R' || h[l].typ=='Q')
                    is=1;
            }
            int r=i;
            if (r<h.size())
            {
                if (h[r].typ=='R' || h[r].typ=='Q')
                    is=1;
            }
            break;
        }
    }
    for (int i=0;i<v.size();i++)
    {
        if (v[i].x>X)
        {
            int l=i-1;
            if (l>=0)
            {
                if (v[l].typ=='R' || v[l].typ=='Q')
                    is=1;
            }
            int r=i;
            if (r<v.size())
            {
                if (v[r].typ=='R' || v[r].typ=='Q')
                    is=1;
            }
            break;
        }
    }for (int i=0;i<d2.size();i++)
    {
        if (d2[i].x>X)
        {
            int l=i-1;
            if (l>=0)
            {
                if (d2[l].typ=='B' || d2[l].typ=='Q')
                    is=1;
            }
            int r=i;
            if (r<d2.size())
            {
                if (d2[r].typ=='B' || d2[r].typ=='Q')
                    is=1;
            }
            break;
        }
    }
    for (int i=0;i<d1.size();i++)
    {
        if (d1[i].x>X)
        {
            int l=i-1;
            if (l>=0)
            {
                if (d1[l].typ=='B' || d1[l].typ=='Q')
                    is=1;
            }
            int r=i;
            if (r<d1.size())
            {
                if (d1[r].typ=='B' || d1[r].typ=='Q')
                    is=1;
            }
            break;
        }
    }
    if (is)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}