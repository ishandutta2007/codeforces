n = int(input())
lst = list(map(int,input().split()))
ans = []
nsp = 0
edpos = []
twpos = []
for i in range(n-1,-1,-1):
    if lst[i] == 1:
        ans.append([i, nsp])
        edpos.append([i, nsp])
        nsp += 1
    if lst[i] == 2:
        if len(edpos):
            k = edpos[-1]
            edpos.pop()
            ans.append([i, k[1]])
            twpos.append([i, k[1]])
        else:
            print(-1)
            exit()
    if lst[i] == 3:
        if len(twpos):
            k = twpos[-1]
            twpos.pop()
            ans.append([i, nsp])
            ans.append([k[0], nsp])
            twpos.append([i, nsp])
            nsp += 1
        elif len(edpos):
            k = edpos[-1]
            edpos.pop()
            ans.append([i, nsp])
            ans.append([k[0], nsp])
            twpos.append([i, nsp])
            nsp += 1
        else:
            print(-1)
            exit()
print(len(ans))
for i in ans:
    print(n - i[1], i[0] + 1)