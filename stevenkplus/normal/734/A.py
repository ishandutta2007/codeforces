r = raw_input
r()
s = r()
diff = sum(1 if ch == 'A' else -1 for ch in s)
print 'Anton' if diff > 0 else ('Danik' if diff < 0 else 'Friendship')