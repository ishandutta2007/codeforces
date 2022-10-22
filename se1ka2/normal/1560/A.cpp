#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> v;
    int i = 1;
    while((int)v.size() < 1000){
        if(i % 3 != 0 && i % 10 != 3) v.push_back(i);
        i++;
    }
    while(t--){
        int k;
        cin >> k;
        cout << v[k - 1] << endl;
    }
}