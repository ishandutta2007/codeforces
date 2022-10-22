#include<iostream>

using namespace std;

int find(int q[] , int ss , int s){
	int mini[2];
	mini[0] = 1000;
	for(int i = ss ; i < s ; i++){
		if(q[i] < mini[0]){
			mini[0] = q[i];
			mini[1] = i;
		}
	}
	return mini[1];
}

int main(){
	int q  , n , a[100] , ch , h;
	cin>>q;
	while(q > 0){
		ch = 0;
		cin>>n;
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		while(ch < n){
			h = ch;
			ch = find(a , h , n);
			for(int j = ch ; j > h ; j--){
				swap(a[j] , a[j - 1]);
			}
			if(find(a , h , n) == ch){
				ch++;
			}
		}
		for(int i = 0 ; i < n ; i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		q--;
	}
	return 0;
}