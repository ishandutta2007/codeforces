#include<stdio.h>
#include<stack>
#include<math.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>
#include<stack>
using namespace std;
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
typedef long long LL;
#define vint vector<int>
using namespace std;
#pragma comment(linker, "/STACK:167177216")
int main()
{
    int a,b;
    string s;
    cin >> a >> b >> s;
    int l = a;
    int ans = 0;
    if(b != 2)
        for(int i = 0;i < l - 1;++i)
        {
            if(s[i] == s[i + 1])
            {
                s[i + 1] = s[i] + 1;
                if(s[i + 1] - 'A' == b)
                    s[i + 1] = 'A';
                ans++;
                if(i + 2 < l)
                    if(s[i + 1] == s[i + 2])
                    {
                        s[i + 1]++;
                        if(s[i + 1] - 'A' == b)
                            s[i + 1] = 'A';
                    }
            }

        }
    else
    {
        int t1 = 0,t2 = 0;
        for(int i = 0;i < l;++i)
        {
            if(i & 1)
            {
                if(s[i] == 'A')
                    t1++;
                else
                    t2++;
            }
            else
            {
                if(s[i] == 'A')
                    t2++;
                else
                    t1++;
            }
        }
        int u = 0;
        cout << min(t1,t2) << endl;
        if(t1 < t2)
        {
            for(int i = 0;i < l;++i)
            {
                if(!(u & 1))
                    cout << 'A';
                else
                    cout << 'B';
                u++;
                u = u & 1;
            }
        }
        else
        {
            for(int i = 0;i < l;++i)
            {
                if(!(u & 1))
                    cout << 'B';
                else
                    cout << 'A';
                u++;
                u = u & 1;
            }
        }
        return 0;
    }
    cout << ans << endl << s << endl;
    return 0;
}