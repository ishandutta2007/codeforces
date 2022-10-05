def sort(a):
    n = len(a)
    b = [0 for i in range(n)]
    log = []
    def mergeSort(l, r):
        if r - l <= 1:
            return
        m = (l + r) >> 1
        mergeSort(l, m)
        mergeSort(m, r)
        print(l, r)
        i, j, k = l, m, l
        while i < m and j < r:
            if a[i] < a[j]:
                log.append('0')
                b[k] = a[i]
                i += 1
            else:
                log.append('1')
                b[k] = a[j]
                j += 1
            k += 1
        while i < m:
            b[k] = a[i]
            i += 1
            k += 1
        while j < r:
            b[k] = a[j]
            j += 1
            k += 1
        for p in range(l, r):
            a[p] = b[p]
    mergeSort(0, n)
    return "".join(log)
def unsort(n, log):
    ind = [0, 1]
    a = [i + 1 for i in range(n)]
    b = [0 for i in range(n)]
    def mergeSort(l, r):
        if r - l <= 1:
            return
        m = (l + r) >> 1
        mergeSort(l, m)
        mergeSort(m, r)
        i, j, k = l, m, l
        while i < m and j < r:
            if ind[0] == len(log):
                ind[1] = -1
                return
            if log[ind[0]] == '0':
                ind[0] += 1
                b[k] = a[i]
                i += 1
            else:
                ind[0] += 1
                b[k] = a[j]
                j += 1
            k += 1
        while i < m:
            b[k] = a[i]
            i += 1
            k += 1
        while j < r:
            b[k] = a[j]
            j += 1
            k += 1
        for p in range(l, r):
            a[p] = b[p]
    mergeSort(0, n)
    if ind[0] == len(log) and ind[1] == 1:
        return a
    return [-1]
st = input()
for k in range(1, 1001):
    v = unsort(k, st)
    if v[0] == -1:
        continue
    mg = [0 for i in range(k)]
    print(k)
    for i in range(k):
        mg[v[i] - 1] = i + 1
    print(*mg)
    break
#print(sort(mg))