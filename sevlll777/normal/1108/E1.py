n, m = list(map(int, input().split()))
A = list(map(int, input().split()))
if n > 300:
    lst = []
    for i in range(m):
        a, b = list(map(int, input().split()))
        lst.append([a, b])
    answer = 0
    answer_1 = []
    m300 = [[-1, -10**6]]
    for i in range(max(0, m-1)):
        m300.append([-1, -10**6])
    for u in range(n):
        if A[u] > min(m300)[1]:
            m300[m300.index(min(m300))] = [u, A[u]]
    for i, mi in m300:
        B = A.copy()
        kek = []
        for j in range(m):
            a, b = lst[j][0], lst[j][1]
            if a <= i + 1 <= b:
                kek.append(j + 1)
                for q in range(a - 1, b):
                    B[q] -= 1
        elem = max(B)
        if answer < elem - mi:
            answer = elem - mi
            answer_1 = kek.copy()
    print(answer)
    print(len(answer_1))
    print(' '.join(map(str, answer_1)))
else:
    lst = []
    for i in range(m):
        a, b = list(map(int, input().split()))
        lst.append([a, b])
    answer = 0
    answer_1 = []
    for i in range(n):
        B = A.copy()
        kek = []
        for j in range(m):
            a, b = lst[j][0], lst[j][1]
            if a <= i + 1 <= b:
                kek.append(j + 1)
                for q in range(a - 1, b):
                    B[q] -= 1
        elem = max(B)
        if answer < elem - B[i]:
            answer = elem - B[i]
            answer_1 = kek.copy()
    print(answer)
    print(len(answer_1))
    print(' '.join(map(str, answer_1)))