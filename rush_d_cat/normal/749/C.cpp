#include <iostream>
#include <set>
#include <queue>
#include <vector>
using namespace std;
const int NICO = 200000 + 10;
set<int> st;
queue<int> dd, rr;
char s[NICO];
int d[NICO], r[NICO];
int D, R;
int n;
vector<int> del;
int main()
{
    cin >> n;
    scanf("%s", s+1);
    for(int i=1;i<=n;i++)
    {
        st.insert(i);
    }
    set<int>::iterator it;
    while(1) 
    {
        del.clear();
        bool hasd = 0, hasr = 0;
        for(it = st.begin(); it!=st.end(); it++)
        {
            int i = *it;
            if(s[i] == 'D')
            {
                hasd = 1;
                if(R > D) 
                {
                    del.push_back(i);
                }
                D++;
            }
            if(s[i] == 'R')
            {
                hasr = 1;
                if(D > R)
                {
                    del.push_back(i);
                }
                R++;
            }
        }
        for(int i=0;i<del.size();i++)
        {
            st.erase(del[i]);
        }
        if(hasd == 0)
        {
            cout << "R" << endl;
            return 0;
        } 
        if(hasr == 0)
        {
            cout << "D" << endl;
            return 0;
        }
    }
}