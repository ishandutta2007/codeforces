m = int(input())
S = list(map(int, input().split()))
if S[0] != 1:
    for i in range(1, m):
        if S[i] % S[0]:
            print(-1)
            exit(0)
SS = []
for i in range(m):
    SS.append(S[0])
    SS.append(S[i])
SS.append(S[0])
print(len(SS))
print(*SS)