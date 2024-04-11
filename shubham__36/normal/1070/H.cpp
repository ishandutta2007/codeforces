#include<bits/stdc++.h> 
using namespace std; 
#define ll long long int
#define v vector<ll>
#define vv vector<v>
#define p pair<ll,ll>
#define MAX 15000001
#define fi first
#define se second
#define pp pair<p,int>
#define pi pair<int,p>
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    map<string,int> counter;
    map<string,int> index;
    vector<string> arr(n+1);
    for (int k=1; k<=n; k++)
    {
        string s;
        cin>>s;
        arr[k]=s;
        int n=s.length();
        set<string> temp;
        for (int i=0; i<s.length(); i++)
        {
            int m=n-i;
            for (int j=0; j<=m; j++)
            {
                temp.insert(s.substr(i,j));
            }   
        }
        for (auto it=temp.begin(); it!=temp.end(); it++)
        {
            counter[*it]++;
            index[*it]=k;
        }
    }
    int q;
    cin>>q;
    for (int i=1; i<=q; i++)
    {
        string s;
        cin>>s;
        cout<<counter[s]<<" ";//<<arr[index[s]]<<endl;
        if (counter[s]>0)
            cout<<arr[index[s]]<<endl;
        else
            cout<<"-"<<endl;
    }
    return 0;
}