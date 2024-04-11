#include<bits/stdc++.h>
//#define long long long long
using namespace std;
long long  _mergeSort(long long arr[], long long temp[], long long left, long long right);
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right);
long long mergeSort(long long arr[], long long array_size)
{
    long long *temp = (long long *)malloc(sizeof(long long)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
long long _mergeSort(long long arr[], long long temp[], long long left, long long right)
{
  long long mid, inv_count = 0;
  if (right > left)
  {
    mid = (right + left)/2;
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
long long merge(long long arr[], long long temp[], long long left, long long mid, long long right)
{
  long long i, j, k;
  long long inv_count = 0;
  i = left;
  j = mid;
  k = left;
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
      inv_count = inv_count + (mid - i);
    }
  }
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  while (j <= right)
    temp[k++] = arr[j++];
  for (i=left; i <= right; i++)
    arr[i] = temp[i];

  return inv_count;
}
long long x[100009],V[100009];
long long F[100009];
long long w;
  pair<long long,long long>   v[100009];
    vector<pair<pair<long long,long long>, long long> > R;
bool compare1(pair<long long,long long> X ,pair<long long,long long> Y){
    if(X.first == 0) return 0;
    if(Y.first == 0) return 1;int e1,e2;
    if(X.first < 0) e1  = -1; else e1 = 1;
    if(Y.first < 0) e2  = -1; else e2 = 1;
    if( (w+X.second)*abs(Y.first)*e1 != (w+Y.second)*abs(X.first)*e2) return
         (w+X.second)*abs(Y.first)*e1 <= (w+Y.second)*abs(X.first)*e2;
    return (-w+X.second)*abs(Y.first)*e1 > (-w+Y.second)*abs(X.first)*e2;
}
bool compare2(pair<pair<long long,long long>,long long> X ,pair<pair<long long,long long>,long long> Y){
    if(X.first.first == 0) return 0;
    if(Y.first.first == 0) return 1;
   int e1,e2;
    if(X.first.first < 0) e1  = -1; else e1 = 1;
    if(Y.first.first < 0) e2  = -1; else e2 = 1;
    if( (-w+X.first.second)*abs(Y.first.first)*e1 != (-w+Y.first.second)*abs(X.first.first)*e2) return
         (-w+X.first.second)*abs(Y.first.first)*e1 < (-w+Y.first.second)*abs(X.first.first)*e2;
     return X.second < Y.second;
}
main(){
    long long n;
    cin >> n >> w;
    for(long long i = 0; i < n; i++){
        cin >> x[i] >> V[i];
        //x[i] = V[i] = i+1;
        v[i]= {x[i],V[i]};
    }
    sort(v,v+n,compare1);
 //   cout << 1 << endl;
    for (long long i = 0; i < n; i++)
       {
        R.push_back({{v[i].first,v[i].second},-i});
        }
    sort(R.begin(),R.end(),compare2);
    long long cnt = 0;
    for (long long i = 0; i < R.size(); i++)
    {
         cnt++;
        F[-R[i].second] = cnt;

    }
    cout << mergeSort(F,n) << endl;
    return 0;
}