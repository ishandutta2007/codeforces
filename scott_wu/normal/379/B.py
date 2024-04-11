n = int(raw_input())

arr = map(int, raw_input().split())

ans = ""
for i in range(n):
    for j in range(arr[i]):
        if i == 0:
            ans += "RLP"
        else:
            ans += "LRP"
    if i < n - 1:
        ans += "R"

print ans