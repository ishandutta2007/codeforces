#include <iostream>
#include <iomanip>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>

using namespace std;
typedef long long ll;
const int MAXN = 150000;

int N;
int x1[MAXN], x2[MAXN], y1[MAXN], y2[MAXN];
vector <pair <int, int> > event;

bool check (int X, int Y)
{
    int cc = 0;
    for (int i = 0; i < N; i++)
    {
        if (X >= x1[i] && X <= x2[i] && Y >= y1[i] && Y <= y2[i])
            cc++;
    }
    return cc >= N - 1;
}

vector <int> xcoords, ycoords;

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    }

    event.clear();
    for (int i = 0; i < N; i++)
    {
        event.push_back(make_pair(x1[i], 1));
        event.push_back(make_pair(x2[i] + 1, -1));
    }
    sort(event.begin(), event.end());

    int cc = 0;
    for (int i = 0; i < event.size(); i++)
    {
        cc += event[i].second;
        if (cc >= N - 2)
            xcoords.push_back(event[i].first);
    }

    event.clear();
    for (int i = 0; i < N; i++)
    {
        event.push_back(make_pair(y1[i], 1));
        event.push_back(make_pair(y2[i] + 1, -1));
    }
    sort(event.begin(), event.end());

    cc = 0;
    for (int i = 0; i < event.size(); i++)
    {
        cc += event[i].second;
        if (cc >= N - 2)
            ycoords.push_back(event[i].first);
    }

    for (int i = 0; i < xcoords.size(); i++)
        for (int j = 0; j < ycoords.size(); j++)
        {
            int X = xcoords[i], Y = ycoords[j];
            //cout << X << " " << Y << "\n";
            if (check (X, Y))
            {
                cout << X << " " << Y << "\n";
                return 0;
            }
        }
}