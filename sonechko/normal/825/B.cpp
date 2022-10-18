#include<bits/stdc++.h>
using namespace std;
bool get(char a, char b, char c, char d, char e)
{
    int kol=0;
    if (a=='X') kol++; else
    if (a=='O') return false;
    if (b=='X') kol++;  else
    if (b=='O') return false;
    if (c=='X') kol++;  else
    if (c=='O') return false;
    if (d=='X') kol++;  else
    if (d=='O') return false;
    if (e=='X') kol++;  else
    if (e=='O') return false;
    if (kol==4) {cout<<"YES"<<endl; exit(0);}
}
char a[11][11];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n=10;
    for (int i=1; i<=n; i++)
    for (int j=1; j<=n; j++)
    cin>>a[i][j];
    for (int i=1; i<=6; i++)
    for (int j=1; j<=10; j++)
    get(a[i][j],a[i+1][j],a[i+2][j],a[i+3][j],a[i+4][j]);
    for (int i=1; i<=10; i++)
    for (int j=1; j<=6; j++)
    get(a[i][j],a[i][j+1],a[i][j+2],a[i][j+3],a[i][j+4]);
    for (int i=1; i<=6; i++)
    for (int j=1; j<=6; j++)
    get(a[i][j],a[i+1][j+1],a[i+2][j+2],a[i+3][j+3],a[i+4][j+4]);
    for (int i=5; i<=10; i++)
    for (int j=1; j<=6; j++)
    get(a[i][j],a[i-1][j+1],a[i-2][j+2],a[i-3][j+3],a[i-4][j+4]);
    cout<<"NO"<<endl;
}