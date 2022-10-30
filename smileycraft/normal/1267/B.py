def run():
    s = input()
    i = 0
    j = len(s)-1
    count = 0
    while i<=j:
        if s[i] != s[j]:
            return 0
        c = s[i]
        count = 0
        while i < len(s) and s[i] == c and i<=j:
            i += 1
            count += 1
        while j >= 0 and s[j] == c and i<=j:
            j -= 1
            count += 1
        if i>j:
            count += 1
            if count >= 3:
                return count
            else:
                return 0
        elif count<3:
            return 0

print(run())