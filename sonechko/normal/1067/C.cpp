#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

char a[3002][3002];
int start_kol,finish_kol;
vector<int> v1,v2;

int get_kol(int l, int r)
{
    int kol=0;
    for (int j=0; j<v1.size(); j++)
        if (a[l+v1[j]][r+v2[j]]=='o'||a[l+v1[j]][r+v2[j]]=='*') kol++;
    //cout<<l<<" "<<r<<" - "<<kol<<endl;
    return kol;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    v1.pb(-2);v1.pb(-2);v1.pb(2); v1.pb(2); v1.pb(-1);v1.pb(-1);v1.pb(1); v1.pb(1);
    v2.pb(-1);v2.pb(1); v2.pb(-1);v2.pb(1); v2.pb(-2);v2.pb(2); v2.pb(-2);v2.pb(2);
    int n=3;
    int m=0;


    //for (int i=1; i<=2002; i++)
    //for (int j=1; j<=2002; j++)
    //8a[i][j]='.';


    int k;
    cin>>k;
    int gg=(k*k)/10;
    while (k>0)
    {
        m++;
        if (m%2==1)
        {
            k--;
            //a[1000+2][1000+m]='*';
            cout<<2<<" "<<m<<endl;
            start_kol++;
            finish_kol++;
        } else
        {
            k--;
            //a[1000+1][1000+m]='*';
            cout<<1<<" "<<m<<endl;
            start_kol++;
            finish_kol++;
            if (k>0)
            {
                k--;
                //a[1000+3][1000+m]='*';
                cout<<3<<" "<<m<<endl;
                start_kol++;
                finish_kol++;
            }
        }
    }
    return 0;


    int t=1;
    int l1=1001,l2=n+1000,r1=1001,r2=m+1000;
    while (t>0)
    {
        t=0;
        cout<<"! "<<finish_kol<<endl;
        for (int i=2; i<=2000; i++)
        for (int j=2; j<=2000; j++)
        if (a[i][j]=='.'&&get_kol(i,j)>=4)
        {
            a[i][j]='o';
            l1=min(l1,i);
            r1=min(r1,j);
            l2=max(l2,i);
            r2=max(r2,j);
            finish_kol++;
            t=1;
        }
    }
    cout<<"! "<<start_kol<<" -> "<<finish_kol<<"( "<<gg<<" ) "<<endl;
    for (int i=l1; i<=l2; i++)
    {
        for (int j=l1; j<=r2; j++)
            cout<<a[i][j];
        cout<<endl;
    }



}
/**
3 33
.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.
*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.
*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.
*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*
**/