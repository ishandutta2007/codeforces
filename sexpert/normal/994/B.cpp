#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> powers, costsUns;
int n, k, aux;

int main()
{
    vector<int> powHierarchy, cash;
    long long ans[100005];
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        powers.push_back(make_pair(aux, i));
    }
    for(int i = 0; i < n; i++)
    {
        cin >> aux;
        costsUns.push_back(make_pair(aux, i));
        cash.push_back(aux);
    }
    sort(powers.begin(), powers.end());
    sort(cash.begin(), cash.end());
    for(auto p : powers) powHierarchy.push_back(p.second);
    priority_queue<int> curr;
    long long sum = 0;
    for(int i = 0; i < n; i++)
    {
        int ind = powHierarchy[i];
        int cost = costsUns[ind].first;
        long long tot = 0;
        tot += sum;
        tot += costsUns[ind].first;
        if(curr.size() < k || k == 0) 
        {
            curr.push(-cost);
            sum += cost;
            if(k == 0) sum = 0;
        }
        else if(-curr.top() < cost)
        {
            sum += curr.top();
            curr.pop();
            curr.push(-cost);
            sum += cost;
        }
        ans[ind] = tot;
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}