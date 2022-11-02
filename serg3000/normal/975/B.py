a = list(map(int,input().split()))
ans = 0
b = [0] * 14
for i in range(14):
    for l in range(14):
        b[l] = a[l]
    cnt = 0
    k = a[i] // 14
    k2 = a[i] % 14
    b[i] = 0
    for j in range(14):
        b[j] += k;
    for j in range(i + 1, i + k2 + 1): 
        b[j % 14] += 1;
    for j in range(14):
        if b[j] % 2 == 0:
            cnt += b[j]
        #print(b[j], end = " ")
    #print(cnt)
    
    if ans < cnt:
        ans = cnt
print(ans)