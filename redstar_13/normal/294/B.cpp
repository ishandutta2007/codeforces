#include <bits/stdc++.h>



using namespace std;



int n, w, h, a[200], b[200], at, bt, ans=1000;

int main()

{

//	freopen ("in.txt", "r", stdin);

	scanf ("%d", &n);

	for (int i=1; i<=n; i++){

		scanf ("%d%d", &w, &h);

		if(w==2) a[++at]=h;

		else b[++bt]=h;

	}

	sort(a+1, a+at+1); sort(b+1, b+bt+1);

	for (int i=1; i<=at; i++){

		for (int j=1; j<=bt; j++){

			int tot=0;

			for (int k=1; k<=at-i; k++) tot+=a[k];

			for (int k=1; k<=bt-j; k++) tot+=b[k];

			if(i*2+j>=tot) ans=min(i*2+j, ans);

		}

	}

	for (int i=1; i<=bt; i++){

		int tot=0;

		for (int k=1; k<=bt-i; k++) tot+=b[k];

		for (int k=1; k<=at; k++) tot+=a[k];

		if(i>=tot) ans=min(i, ans);

	}

	for (int i=1; i<=at; i++){

		int tot=0;

		for (int k=1; k<=at-i; k++) tot+=a[k];

		for (int k=1; k<=bt; k++) tot+=b[k];

		if(i*2>=tot) ans=min(i*2, ans);

	}

	cout<<ans<<endl;

	return 0;

}