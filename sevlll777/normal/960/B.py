n, k1, k2 = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))


def just_relax():
    global gruz
    mam = 0
    ind = -1
    for i in range(n):
        if abs(A[i] - B[i]) > mam:
            mam = abs(A[i] - B[i])
            ind = i
    if ind != -1:
        if A[ind] < B[ind]:
            A[ind] += 1
        else:
            A[ind] -= 1
    else:
        gruz = 1


gruz = 0
ans = 0
for iq in range(k1 + k2):
    just_relax()
    if gruz:
        if (k1 + k2 - iq) % 2 == 0:
            print(0)
        else:
            print(1)
        exit(0)
for i in range(n):
    ans += abs(A[i] - B[i]) ** 2
print(ans)