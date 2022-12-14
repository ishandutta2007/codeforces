
 #include<bits/stdc++.h>
using namespace std;
multiset<int> s;
int main()
{
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        s.insert(x);
    }
    while(s.size())
    {
        cout<< *(s.begin()) << " ";
        s.erase(s.begin());
        if (s.size())
        {
            cout<< *(--s.end()) <<" ";

            s.erase(--s.end());
        }

    }
    cout<<endl;
}