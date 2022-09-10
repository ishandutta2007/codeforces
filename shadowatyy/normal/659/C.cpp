#include <bits/stdc++.h>
using namespace std;

vector <int> V;
vector <int> res;

int n, k, w, sum;

bool comp(int a, int b)
{
    return a>b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> n >> k;

    for(int i = 1; i <= n; i++)
    {
        cin >> w;

        V.push_back(w);
    }

    sort(V.begin(), V.end(), comp);

    for(int i = 1; i <= 1000000; i++)
    {

        if(!V.empty())
        {
            if(V.back()==i)
            {
                V.pop_back();
                continue;
            }
        }

        if(sum+i<=k)
        {
            sum += i;
            res.push_back(i);
        }
        else
        {
            break;
        }
    }

    cout << res.size() << '\n';

    for(int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}