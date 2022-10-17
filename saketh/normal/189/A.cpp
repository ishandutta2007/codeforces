#include<iostream>
using namespace std;

int n, a, b, c, m[8005]; 

int main(){
    cin >> n >> a >> b >> c;
    m[a] = m[b] = m[c] = 1;
    for(int o=1; o<=n; o++)
        if(m[o]){
            m[o+a] = max(m[o+a], m[o]+1);
            m[o+b] = max(m[o+b], m[o]+1);
            m[o+c] = max(m[o+c], m[o]+1);
        }
    cout << m[n] << endl;
}