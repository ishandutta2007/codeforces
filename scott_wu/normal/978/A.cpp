#include <iostream>
#include <vector>

using namespace std;
const int MAXN = 51;

int N;
int arr[MAXN];
vector <int> v;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    for (int i = 0; i < N; i++)
    {
        bool bad = false;
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] == arr[j])
            {
                bad = true;
                break;
            }
        }
        if (!bad)
            v.push_back(arr[i]);
    }

    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
}