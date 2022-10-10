#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int n, count[5001] = {0};
    fin >> n;
    for (int i=0; i<n; i++) {
        int c;
        fin >> c;
        count[c]++;
    }
    
    int ret = INT_MAX;
    for (int i=1; i<=5000; i++) {
        int sum = 0;
        for (int j=1; j<i; j++)
            sum += count[j];
        for (int j=5000; j>2*i; j--)
            sum += count[j];
        ret = min(ret, sum);
    }
    
    fout << ret << endl;
    
    return 0;
}