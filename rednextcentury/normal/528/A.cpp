# include <iostream>
# include<algorithm>
#include <stdio.h>
# include <cstdlib>
# include <ios>
# include <set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    set<long long> cut1;
    set<long long> cut2;
    multiset<long long> val1;
    multiset<long long> val2;
    long long h,w;
    cin>>w>>h;
    cut1.insert(0);
    cut1.insert(w);
    cut2.insert(0);
    cut2.insert(h);
    val1.insert(w);
    val2.insert(h);
    long long n;
    cin>>n;
    for (long long i=0;i<n;i++)
    {
        char typ;
        long long val;
        cin>>typ>>val;
        if (typ=='H')
        {
            multiset<long long>::iterator it=cut2.upper_bound(val);
            long long s1=*it;
            it--;
            long long s2=*it;
            cut2.insert(val);
            it=val2.find(s1-s2);
            val2.erase(it);
            val2.insert(s1-val);
            val2.insert(val-s2);
        }
        else
        {
            multiset<long long>::iterator it=cut1.upper_bound(val);
            long long s1=*it;
            it--;
            long long s2=*it;
            cut1.insert(val);
            it=val1.find(s1-s2);
            val1.erase(it);
            val1.insert(s1-val);
            val1.insert(val-s2);
        }
        set<long long>::iterator it1=val1.end();
        it1--;
        set<long long>::iterator it2=val2.end();
        it2--;
        cout<<(*it1)*(*it2)<<endl;
    }
}