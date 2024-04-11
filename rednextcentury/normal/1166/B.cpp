#include <bits/stdc++.h>
using namespace std;
string s[] = {
        "aeiou",
        "eioua",
        "iouae",
        "ouaei",
        "uaeio"
};
bool is[3010][3010];
char ret[3010][3010];
void solve(int n,int m)
{
    for (int i=0;i<5;i++)
        for (int j=0;j<5;j++)
            is[i][j]=1,ret[i][j]=s[i][j];

    for (int i=5;i<n;i++)
        for (int j=0;j<5;j++)
            is[i][j]=1,ret[i][j]=s[0][j];

    for (int i=5;i<m;i++)
        for (int j=0;j<5;j++)
            is[j][i]=1,ret[j][i]=s[0][j];

    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (!is[i][j])
                ret[i][j] = 'a';

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
            cout<<ret[i][j];
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 5; i <= n; i++)
    {
        if (n%i==0 && n/i>=5)
        {
            solve(i,n/i);
            return 0;
        }
    }
    cout<<-1<<endl;
}