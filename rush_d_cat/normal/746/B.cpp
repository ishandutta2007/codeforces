#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int NICO = 2005;
char s[NICO], res[NICO];
int main()
{
    int n;cin >> n;
    scanf("%s", s+1);
    if(n%2==1) 
    {
        int mid = (1+n) / 2;
        int d = 1;
        res[mid] = s[1];
        for(int i=2;i<=n;i++)
        {
            if(i%2==0)
            {
                res[mid-d] = s[i];
            } else {
                res[mid+d] = s[i];
                d++;
            }
        }
    } else {
        int mid = (1+n)/2;
        for(int i=1;i<=n;i++)
        {
            if(i%2==1)
            {
                res[mid] = s[i];
            } else {
                res[n+1-mid]=s[i];
                mid --;
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<res[i];
}