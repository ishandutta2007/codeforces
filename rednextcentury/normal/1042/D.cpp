#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
#define ll long long
using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<long long,long long>,
null_type,
less<pair<long long,long long> >,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

long long a[1000000];
int main()
{
    ordered_set X;
    int n;
    long long t;
    cin>>n>>t;
    X.insert({0,-1});
    long long sum=0;
    long long ret=0;
    for (int i=0;i<n;i++)
    {
        cin>>a[i];
        sum+=a[i];
        ret+=X.size()-X.order_of_key({sum-t+1,-1e9});
        X.insert({sum,i});
    }
    cout<<ret<<endl;
    /*
    X.insert(1);
    X.insert(2);
    X.insert(4);
    X.insert(8);
    X.insert(16);

    cout<<*X.find_by_order(1)<<endl; // 2
    cout<<*X.find_by_order(2)<<endl; // 4
    cout<<*X.find_by_order(4)<<endl; // 16
    cout<<(end(X)==X.find_by_order(6))<<endl; // true

    cout<<X.order_of_key(-5)<<endl;  // 0
    cout<<X.order_of_key(1)<<endl;   // 0
    cout<<X.order_of_key(3)<<endl;   // 2
    cout<<X.order_of_key(4)<<endl;   // 2
    cout<<X.order_of_key(400)<<endl; // 5
    */
}