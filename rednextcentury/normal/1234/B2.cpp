#include <bits/stdc++.h>
using namespace std;
set<int> cur;
deque<int> q;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k;
    cin>>n>>k;
    for (int i=0;i<n;i++) {
        int id;
        cin>>id;
        if (cur.find(id)!=cur.end())continue;
        else {
            if (cur.size()==k) {
                int x = q.back();
                q.pop_back();
                cur.erase(x);
                cur.insert(id);
                q.push_front(id);
            } else {
                q.push_front(id);
                cur.insert(id);
            }
        }
    }
    cout<<q.size()<<endl;
    for (int i=0;i<q.size();i++) {
        cout<<q[i]<<' ';
    }
}