#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
#define mp make_pair
#define pb push_back

const int N = 1e5 + 11;

char a[10][10];

void good(int l1, int r1, int l2, int r2)
{
    int ps=0;
    for (int x=l1; x<=r1; x++)
    for (int y=l2; y<=r2; y++)
    if (a[x][y]=='.') ps=1;
    if (ps==1)
    {
        for (int i=1; i<=9; i++)
        {
            for (int j=1; j<=9; j++)
        {
            if (a[i][j]=='x'||a[i][j]=='o') cout<<a[i][j]; else
            if (i>=l1&&i<=r1&&j>=l2&&j<=r2) cout<<"!"; else cout<<".";
            if (j%3==0) cout<<" ";
        }
        cout<<endl;
        if (i%3==0) cout<<endl;
        }
        return;
    }
    for (int i=1; i<=9; i++)
    {
        for (int j=1; j<=9; j++)
    {
        if (a[i][j]=='x'||a[i][j]=='o') cout<<a[i][j]; else cout<<"!";
        if (j%3==0) cout<<" ";
    }
    cout<<endl;
    if (i%3==0) cout<<endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int p=1; p<=9; p++)
    for (int d=1; d<=9; d++)
    cin>>a[p][d];
    int x,y;
    cin>>x>>y;
    if (x%3==1&&y%3==1) good(1,3,1,3);
    if (x%3==1&&y%3==2) good(1,3,4,6);
    if (x%3==1&&y%3==0) good(1,3,7,9);
    if (x%3==2&&y%3==1) good(4,6,1,3);
    if (x%3==2&&y%3==2) good(4,6,4,6);
    if (x%3==2&&y%3==0) good(4,6,7,9);
    if (x%3==0&&y%3==1) good(7,9,1,3);
    if (x%3==0&&y%3==2) good(7,9,4,6);
    if (x%3==0&&y%3==0) good(7,9,7,9);

}