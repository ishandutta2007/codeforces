# include <iostream>
# include <algorithm>
# include <set>
# include <stdio.h>
using namespace std;
set<int> s;
int k,a;
int now=0;
bool add(int x)
{
    s.insert(x);
    set<int>::iterator it=s.find(x);
    it++;
    int e=*it;
    it--;
    it--;
    int s=*it;
    now -= (e-s)/(a+1);
    now += (e-x)/(a+1);
    now+=(x-s)/(a+1);
    if (now<k)
        return 1;
    return 0;
}
int main()
{
    int n;
    cin>>n>>k>>a;
    s.insert(0);
    s.insert(n+1);
    int m;
    cin>>m;
    now=(n+1)/(a+1);
    for (int i=0;i<m;i++)
    {
        int x;
        cin>>x;
        if (add(x))
        {
            cout<<i+1<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
}