n, m, k = [int(s) for s in input().split()]
x = [int(input()) for i in range(m)]
Fedor=int(input())
Fedor_bin=list(str(bin(Fedor)).replace('0b','').zfill(n))
total=0
for i in x:
	x_bin= list(str(bin(i)).replace('0b','').zfill(n))
	rev_Fedor_bin=Fedor_bin[::-1]
	rev_x_bin=x_bin[::-1]
	count=0
	for j in range(len(Fedor_bin)):
		if rev_Fedor_bin[j] != rev_x_bin[j]:
			count+=1
	else:
		if count<=k:
			total+=1

print(total)