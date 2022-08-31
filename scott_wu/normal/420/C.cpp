#include <iostream>
#include <algorithm>
#include <map>

using namespace std;
const int MAXN = 300100;

int N, P;
int arr[MAXN];
int arr2[MAXN];
pair <int, int> res[MAXN];

map <pair <int, int>, int> mmap;

int main()
{
    for (int i = 0; i < MAXN; i++)
        arr[i] = 0;
    
    cin >> N >> P;
    for (int i = 0; i < N; i++)
    {
        cin >> res[i].first >> res[i].second;
        res[i].first--, res[i].second--;
        arr[res[i].first]++;
        arr[res[i].second]++;
        
        if (res[i].first > res[i].second)
            swap (res[i].first, res[i].second);
    }
    
    for (int i = 0; i < N; i++)
        arr2[i] = arr[i];
    sort (arr, arr + N);
    
    int lo = 0;
    long long tot = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        while (lo < i && arr[lo] + arr[i] < P)
            lo++;
        tot += max (0, i - lo);
    }
    
    for (int i = 0; i < N; i++)
    {
        if (mmap.find (res[i]) != mmap.end())
            mmap[res[i]]++;
        else
            mmap[res[i]] = 1;
    }
    
    for (map <pair <int, int>, int>::iterator it = mmap.begin(); it != mmap.end(); it++)
    {
        int left = it->first.first;
        int right = it->first.second;
        int val = it->second;
        
        if (arr2[left] + arr2[right] >= P && arr2[left] + arr2[right] - val < P)
            tot--;
    }
    cout << tot << "\n";
    return 0;
}