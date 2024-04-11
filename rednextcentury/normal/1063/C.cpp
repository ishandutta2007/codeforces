#include <bits/stdc++.h>
using namespace std;
map<int,int> mp;
int num=-1;
vector<int> b,w;
int query(int x,int y)
{
    if (++mp[y]>1)
    {
        if (!mp[y+1])y++;
        else if(!mp[y-1])y--;
        else x+=10;
    }
   cout<<x<<' '<<y<<endl;
   fflush(stdout);
   string s;
    cin>>s;
    if (s=="black")return 1;
    else return 0;

}
void answer(int x1,int y1,int x2,int y2)
{
    cout<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
    fflush(stdout);
    return;
}
int main()
{
    srand(time(NULL));
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int l=0,r=1e9;
    int col=query(1,0);
    b.push_back(0);
    n--;
    if (n==0)
    {
        answer(1,1,2,1);
        return 0;
    }
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        int x = query(1,mid);
        if (x==col)b.push_back(mid);
        else w.push_back(mid);
        n--;
        if (n==0)
        {
            if (x==col)
                answer(0,mid+1,2,mid+1);
            else
                answer(0,mid-1,2,mid-1);
            return 0;
        }
        if (x!=col)break;
        else l=mid;
    }
    r=mid;
    while(n--)
    {
        mid=(l+r)/2;
        if (query(1,mid)==col)
            l=mid,b.push_back(mid);
        else
            r=mid,w.push_back(mid);
    }
    sort(b.begin(),b.end());
    /*for (int i=0;i<b.size();i++)
        cout<<b[i]<<' ';
    cout<<endl;

    */sort(w.begin(),w.end());
    /*for (int i=0;i<w.size();i++)
        cout<<w[i]<<' ';
    cout<<endl;*/
    answer(0,b[b.size()-1]+1,2,b[b.size()-1]);
    return 0;
}