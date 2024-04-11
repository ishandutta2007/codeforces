def leap(y)
  return y % 400 == 0 || (y % 100 != 0 && y % 4 == 0)
end

def check_time(t, s, m, h)
  return false unless s == -1 || t.sec == s
  return false unless m == -1 || t.min == m
  return false unless h == -1 || t.hour == h
  true
end

def fix_time(t, s, m, h)
  loop do
    ok = true

    if h != -1 && t.hour != h
      ok = false
      t += 1 while t.sec != 0
      t += 60 while t.min != 0
      t += 3600 while t.hour != h
    end

    if m != -1 && t.min != m
      ok = false
      t += 1 while t.sec != 0
      t += 60 while t.min != m
    end

    if s != -1 && t.sec != s
      ok = false
      t += 1 while t.sec != s
    end
    
    break if ok
  end

  t += 1 until check_time(t, s, m, h)
  t
end

def check_date(t, day, date, month)
  return false unless month == -1 || t.month == month
  if day != -1 && date != -1
    return day == t.wday || date == t.mday
  else
    return false unless day == -1 || t.wday == day
    return false unless date == -1 || t.mday == date
    return true
  end
end

def fix_date(t, day, date, month)
  until check_date(t, day, date, month)
    if month != -1 && t.month != month && t.mday == 1
      t += 28 * 86400
    else
      t += 86400
    end
  end
  t
end

s, m, h, day, date, month = gets.split.map(&:to_i)
day %= 7 if day != -1
q = gets.to_i
q.times do
  epoch = gets.to_i
  t = Time.at(epoch).utc + 1
  t = fix_time(t, s, m, h)
  t += 86400 - t.to_i % 86400 unless check_date(t, day, date, month)
  t = fix_time(t, s, m, h)
  t = fix_date(t, day, date, month)
  puts t.to_i
end