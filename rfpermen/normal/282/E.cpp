// C++ program for a Trie based O(n) solution to find max
// subarray XOR
#include<bits/stdc++.h>
using namespace std;
 
// Assumed int size
#define INT_SIZE 41
#define ll long long
ll ini;
// A Trie Node
struct TrieNode
{
    ll value;  // Only used in leaf nodes
    TrieNode *arr[2];
};
 
// Utility function tp create a Trie node
TrieNode *newNode()
{
    TrieNode *temp = new TrieNode;
    temp->value = 0;
    temp->arr[0] = temp->arr[1] = NULL;
    return temp;
}
 
// Inserts pre_xor to trie with given root
void insert(TrieNode *root, ll pre_xor)
{
    TrieNode *temp = root;
 
    // Start from the msb, insert all bits of
    // pre_xor into Trie
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1LL<<i);
 
        // Create a new node if needed
        if (temp->arr[val] == NULL)
            temp->arr[val] = newNode();
 
        temp = temp->arr[val];
    }
 
    // Store value at leaf node
    temp->value = pre_xor;
}
 
// Finds the maximum XOR ending with last number in
// prefix XOR 'pre_xor' and returns the XOR of this maximum
// with pre_xor which is maximum XOR ending with last element
// of pre_xor.
ll query(TrieNode *root, ll pre_xor)
{
    TrieNode *temp = root;
    for (int i=INT_SIZE-1; i>=0; i--)
    {
        // Find current bit in given prefix
        bool val = pre_xor & (1LL<<i);
 
        // Traverse Trie, first look for a
        // prefix that has opposite bit
        if (temp->arr[1-val]!=NULL)
            temp = temp->arr[1-val];
 
        // If there is no prefix with opposite
        // bit, then look for same bit.
        else if (temp->arr[val] != NULL)
            temp = temp->arr[val];
    }
    return pre_xor^(temp->value);
}
 
// Returns maximum XOR value of a subarray in arr[0..n-1]
ll maxSubarrayXOR(ll arr[], ll n)
{
    // Create a Trie and insert 0 into it
    TrieNode *root = newNode();
    insert(root, 0);
    
    // Initialize answer and xor of current prefix
    ll result = ini, pre_xor =0;
 
    // Traverse all input array element
    for (int i=0; i<n; i++)
    {
        // update current prefix xor and insert it into Trie
        pre_xor = pre_xor^arr[i];
        insert(root, pre_xor);
 
        // Query for current prefix xor in Trie and update
        // result if required
        result = max(result, query(root, pre_xor^ini));
    }
    return result;
}
 
// Driver program to test above functions
int main()
{	
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll arr[100000],n;
    cin>>n;
    for(int i = 0; i<n; i++)cin>>arr[i], ini^=arr[i];
    cout << maxSubarrayXOR(arr, n);
    return 0;
}