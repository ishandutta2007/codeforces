#pragma comment(linker, "/STACK:167177216")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<string>
#include<set>
#include<memory.h>
#include<vector>
#include<map>
#include<queue>

using namespace std;

typedef long long li;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair

pair<int,string> ans[10];

int main()
{
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;


    forn (i, 10)
    {
        int cnt = 0;
        forn (j, s.size())
            if(s[j] - '0' == i )
                cnt++;
        ans[i].second = s;
        for (int l = 1; l < 10; l++)
        {
            forn (j, s.size())
                if((s[j] - '0') - i == l && cnt < k )
                {
                    ans[i].second[j] = i + '0';
                    ans[i].first += l;
                    cnt++;
                }
            for(int j = s.size() - 1; j >= 0; j--)
                if(i - (s[j] - '0') == l && cnt < k )
                {
                    ans[i].second[j] = i + '0';
                    ans[i].first += l;
                    cnt++;
                }
        }
    }
    sort(ans,ans+10);
    cout << ans[0].first<<endl;
    cout << ans[0].second<<endl;
    return 0;
}