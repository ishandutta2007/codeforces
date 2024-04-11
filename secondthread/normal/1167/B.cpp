#include <bits/stdc++.h>

using namespace std;

int main() {
	int nums[6]={4, 8, 15, 16, 23, 42};
	cout<<"? 1 2\n? 2 3\n? 4 5\n? 5 6"<<endl;
	int prods[4];
	for (int i=0; i<4; i++) cin>>prods[i];
	do {
		int p1=nums[0]*nums[1], p2=nums[1]*nums[2], p3=nums[3]*nums[4], p4=nums[4]*nums[5];
//		cout<<p1<<" "<<p2<<" "<<p3<<" "<<p4<<endl;
//		for (int i=0; i<4; i++) cout<<prods[i]<<" ";
//		cout<<endl;
		if (p1==prods[0]&&p2==prods[1]&&p3==prods[2]&&p4==prods[3]) {
			cout<<"! ";
			for (int i=0; i<6; i++)
				cout<<nums[i]<<" ";
			cout<<endl;
			return 0;
		}
	} while (next_permutation(begin(nums), end(nums)));
	cout<<endl;
	
	
	return 0;
}