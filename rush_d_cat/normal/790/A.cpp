#include <iostream>
#include <cstring>
using namespace std;
int n, k, a[150], ok[150];
string s[150], str;
void init()
{
    int cnt = 0;
    for(int i=1;i<=26;i++)
    {
        for(int j=1;j<=5;j++) 
        {
            s[++cnt] += (char)(i + 'A' - 1); 
            s[cnt] += (char)(j + 'a' - 1); 
        }
    }
}
int main()
{
    init();
    cin >> n >> k;
    for(int i=1;i<=n;i++)
    {
        a[i] = i;
    }
    for(int i=1;i<=n-k+1;i++)
    {
        cin >> str;
        if(str[0] == 'N')
        {
            ok[i] = 1;
        }
    }
    for(int i=n-k+1;i>=1;i--)
    {
        if(ok[i])
        {
            a[i] = a[i+k-1];
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << s[a[i]] << " ";
    }
}