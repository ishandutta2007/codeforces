#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

bool op (pair <int,int> a, pair <int,int> b)
{
    return a.second<b.second;
}

int main()
{

    int n,m;
    cin >> n >> m;
    vector <pair <int,int> > st;
    vector <int> times;
    times.resize(n);
    for (int i=0;i<n;i++)
    {
        int t,x;
        pair <int,int> r;
        cin >> t >> x;
        r.first=t;
        r.second=x;
        st.push_back(r);
    }

    int k=n/m;
    int cur=0;

    for (int i=0;i<k;i++)
    {
        vector <pair <int,int> > temp;
        for (int j=0;j<m;j++)
        {
            pair <int,int> r;
            r.first=i*m+j;
            r.second=st[i*m+j].second;
            temp.push_back(r);
        }
        if (cur < st[i*m+m-1].first) cur =st[i*m+m-1].first;
        sort(temp.begin(),temp.end(),op);


        for (int j=0;j<m;)
        {
            int e=1;
            while (j+e<m&&temp[j].second==temp[j+e].second) e++;
            for (int k=j;k<j+e;k++) times[temp[k].first]=st[temp[k].first].second+cur;
            cur+=1+e/2;
            j+=e;
        }
        cur+=2*temp[(int)temp.size()-1].second;
    }
    int p=n-k*m;

        vector <pair <int,int> > temp;
        for (int j=0;j<p;j++)
        {
            pair <int,int> r;
            r.first=k*m+j;
            r.second=st[k*m+j].second;
            temp.push_back(r);
        }
        if (cur < st[k*m+p-1].first) cur =st[k*m+p-1].first;
        sort(temp.begin(),temp.end(),op);


        for (int j=0;j<p;)
        {
            int e=1;
            while (j+e<p&&temp[j].second==temp[j+e].second) e++;
            for (int k=j;k<j+e;k++) times[temp[k].first]=st[temp[k].first].second+cur;
            cur+=1+e/2;
            j+=e;
        }
        for (int i=0;i<n;i++) cout << times[i] << " ";
    return 0;
}