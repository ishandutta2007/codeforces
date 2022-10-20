#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

int x , y , n , m, i , j , k , l;
string s;
vector < pair < char , int > > st;
int sum [ 1000000 ] ;
int good;
vector< pair < int , int > > v;

int count ( int i , int j )
    {
    return sum[ j ] - sum[ i ] + ( s[ i ] == '[' ) ;
    }

int main()
    {
    cin>>s;
    n = s.size();
    sum[0] = (s[0] == '[');
    for (i = 1; i < n; i++)
        sum[i] = sum[i-1] + (s[i] == '[');

    int ans = 0;
    int l = 0 , r = 0;

    for (i = 0; i < n; i++)
        {
        int num = st.size() - 1;
        if (s[i] == '(')
            st.push_back(make_pair(s[i] , i));
        else
        if (s[i] == '[')
            st.push_back(make_pair(s[i] , i));
        else
            if (s[i] == ')' && num >= 0 && st[num].first == '(' || s[i] == ']' && num >= 0 && st[num].first == '[')
                {
                l = st[num].second;
                r = i;
                int sz = v.size() - 1;
                while (v.size() > 0 && v[sz].first > l)
                {
                    v.pop_back();
                    sz--;
                }

                v.push_back(make_pair(l  , r));
                st.pop_back();
                }
            else
                {
                st.clear();
                }
        }

    if (v.size() == 0)
        {
        cout<<0<<endl<<endl;
        return 0;
        }
    sort(v.begin() , v.end());


    i = 0;
    int start = v[0].first;
    while (i < v.size())
        {
        j = i + 1;
        while (j < v.size() && v[j].first == v[j-1].second + 1)
            j++;

        if (count(v[i].first , v[j-1].second) > ans)
            {
            ans = count(v[i].first , v[j-1].second);
            l = v[i].first;
            r = v[j-1].second;
            }

        i = j;
        }

    cout<<ans<<endl<<s.substr(l , r - l + 1)<<endl;


    return 0;
    }