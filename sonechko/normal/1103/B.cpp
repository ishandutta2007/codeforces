#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e6 + 11;

///int g,kol;

bool get(int x, int y)
{
    ///kol++;
    cout<<"? "<<x<<" "<<y<<endl;
    ///int t=0;
    ///if (x%g>=y%g) t=1;
    ///cout<<x%g<<"(x) "<<y%g<<"(y)"<<endl;
    string ch;
    cin>>ch;
    ///if (t==1) ch="x"; else ch="y";
    if (ch=="x") return true;
    if (ch=="y") return false;
    exit(0);
}

void answer(int x)
{
    cout<<"! "<<x<<endl;
}

void up()
{
    ///cin>>g;
    ///kol=0;
    int l=1,r=1000000000;
    while (r-l>1)
    {
        int mid=(l+r)/2;
        //cout<<l<<" "<<r<<" ? "<<l-1<<" "<<min(mid,l*2+1)<<endl;
        int t=get(l-1,min(mid,(l-1)*2+1));
        if (t==1) r=min(mid,(l-1)*2+1); else l=min(mid,(l-1)*2+1)+1;
    }
    int t=get(l-1,l);
    if (t==1) answer(l); else answer(r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    while (1)
    {
        string s;
        cin>>s;
        if (s=="start") up(); else return 0;
    }
}