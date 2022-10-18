#include<bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 2e5 + 11;

int use[N];

void up()
{
    int n;
    cin>>n;
    for (int i=0; i<=9; i++)
        use[i]=0;
    for (int i=1; i<=n; i++)
    {
        char c;
        cin>>c;
        if (c=='L') {for (int j=0; j<=9; j++) if(use[j]==0) {use[j]=1; break;}}
        if (c=='R') {for (int j=9; j>=0; j--) if(use[j]==0) {use[j]=1; break;}}
        if (c>='0'&&c<='9') use[c-'0']=0;
    }
    for (int i=0; i<=9; i++)
        cout<<use[i];
    cout<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    up();
}
/**
1 2 3 4 5 6 7 8 9 10
X
2 3 4 5 6 7 8 9 10
  X
2 4 5 6 7 8 9 10
    X
2 4 6 7 8 9 10
      X
**/